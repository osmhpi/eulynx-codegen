export const metadata = {
  title: 'Test Results',
  description: 'Page description',
}

import { SelectedItemsProvider } from '@/app/selected-items-context'
import TestcaseTable, { Testcase } from './testcase-table'

import data_parse_classes from './Eulynx.Validation-parse-classes-test-result.xml'
import data_generate_c from './Eulynx.Validation-generate-c-test-result.xml'
import data_generate_rust from './Eulynx.Validation-generate-rust-test-result.xml'
import data_generate_csharp from './Eulynx.Validation-generate-csharp-test-result.xml'
import data_generate_klee from './Eulynx.Validation-generate-klee-test-result.xml'
import data_compile_c from './Eulynx.Validation-compile-c-test-result.xml'
import data_compile_klee from './Eulynx.Validation-compile-klee-test-result.xml'
import data_execute_klee from './Eulynx.Validation-execute-klee-test-result.xml'

function CustomersContent() {
  function groupBy<K, V>(list: Array<V>, keyGetter: (input: V) => K): Map<K, Array<V>> {
   const map = new Map<K, Array<V>>();
    list.forEach((item) => {
        const key = keyGetter(item);
        const collection = map.get(key);
        if (!collection) {
            map.set(key, [item]);
        } else {
            collection.push(item);
        }
    });
    return map;
  }

  const data = {
    testsuites: {
      testsuite: [
        ...data_parse_classes.testsuites.testsuite,
        ...data_generate_c.testsuites.testsuite,
        ...data_generate_rust.testsuites.testsuite,
        ...data_generate_csharp.testsuites.testsuite,
        ...data_generate_klee.testsuites.testsuite,
        ...data_compile_c.testsuites.testsuite,
        ...data_compile_klee.testsuites.testsuite,
        ...data_execute_klee.testsuites.testsuite,
      ]
    }
  }

  const components = {
    'Subsystem TDS - EIL': [
      'S_SCI_EfeS_Prim',
      'S_SCI_TDS_Command',
      'S_SCI_TDS_Receive_TVPS',
      'S_SCI_TDS_Receive_Track_Circuit',
      'S_SCI_TDS_Receive_TDP',
    ],
    'Subsystem TDS - Field Element': [
      'F_SCI_EfeS_Sec',
      'F_SCI_TDS_Receive',
      'F_SCI_TDS_Report_TVPS',
      'F_SCI_TDS_Report_Track_Circuit',
      'F_SCI_TDS_Report_TDP'
    ],
    'Subsystem IO - EIL': [
      'S_SCI_EfeS_Prim',
      'S_SCI_IO_Command',
      'S_SCI_IO_Receive',
    ],
    'Subsystem IO - Field Element': [
      'F_SCI_EfeS_Sec',
      'F_SCI_IO_Receive',
      'F_SCI_IO_Report',
    ],
    'Subsystem Level Crossing - EIL': [
      'S_SCI_EfeS_Prim',
      'S_SCI_LC_Command',
      'S_SCI_LC_Receive',
    ],
    'Subsystem Level Crossing - Field Element': [
      'F_SCI_EfeS_Sec',
      'F_SCI_LC_Receive',
      'F_SCI_LC_Report',
    ],
    'Subsystem Light Signal - EIL': [
      'S_SCI_EfeS_Prim',
      'S_SCI_LS_Command',
      'S_SCI_LS_Receive',
    ],
    'Subsystem Light Signal - Field Element': [
      'F_SCI_EfeS_Sec',
      'F_SCI_LS_Receive',
      'F_SCI_LS_Report',
    ],
    'Subsystem Point - EIL': [
      'S_SCI_EfeS_Prim',
      'S_SCI_P_Command_and_Recieve',
    ],
    'Subsystem Point - Field Element': [
      'F_SCI_EfeS_Sec',
      'F_SCI_TDS_Recieve_and_Report_Timeout',
      'F_SCI_P_Report',
    ],
  };

  const testcases = data.testsuites.testsuite.flatMap(x => x.testcase.flatMap(t => ({name: t.$.name, failure: t.failure, skipped: t.skipped})))
  const re = /(.*) \((.*),(.*)\)/;
  const parsed = testcases
    .map(x => ({match: x.name.match(re), ...x}))
    .filter(x => x.match)
    .map(x => ({ test: { testname: x.match![1], ...x}, package: x.match![2], class: x.match![3] }))
  const grouped = groupBy(parsed, x => `${x.package}/${x.class}`);
  const result = Array.from(grouped);
  const t = result.map(([_, value]) => ({ package: value[0].package, class: value[0].class, tests: value.map(x => x.test)}));
  const classStatus = (testcase: Testcase) =>
    testcase.tests.filter(x => x.failure || x.skipped).length > 0 ? 'Failed' : 'Success';
  t.sort((x, y) => x.package.localeCompare(y.package) || classStatus(x).localeCompare(classStatus(y)) || x.class.localeCompare(y.class));

  const allClasses = t.length;

  const stage1Name = 'ClassParsing.ParseClass';
  const stage1Success = t.map(x => x.tests.find(x => x.testname === stage1Name)).filter(x => x !== undefined && !x.failure && !x.skipped).length;

  const stage2Name = 'CodeGeneration.GenerateC';
  const stage2Success = t.map(x => x.tests.find(x => x.testname === stage2Name)).filter(x => x !== undefined && !x.failure && !x.skipped).length;

  const stage3Name = 'Compilation.CompileC';
  const stage3Success = t.map(x => x.tests.find(x => x.testname === stage3Name)).filter(x => x !== undefined && !x.failure && !x.skipped).length;

  const stage4Name = 'SymbolicExecution.ExecuteKlee';
  const stage4Success = t.map(x => x.tests.find(x => x.testname === stage4Name)).filter(x => x !== undefined && !x.failure && !x.skipped).length;

  const componentsSuccesses = Object.entries(components)
    .map(([key, value]) =>
      ({key, value: value.map(component =>
        ({ component, success: t.find(test => test.class === component)?.tests.every(x => !x.failure && !x.skipped) || false })
      )}))

  const allSuccessful = componentsSuccesses.map(thething => ({key: thething.key, success: thething.value.every(x => x.success)}))

  return (
    <div className="px-4 sm:px-6 lg:px-8 py-8 w-full max-w-[96rem] mx-auto">
      {/* Page header */}
      <div className="sm:flex sm:justify-between sm:items-center mb-8">

        {/* Left: Title */}
        <div className="mb-4 sm:mb-0">
          <h1 className="text-2xl md:text-3xl text-slate-800 dark:text-slate-100 font-bold">UML Classes</h1>

          <ul>
            {allSuccessful.map(x => (
              <li key={x.key}>{x.key} - {x.success ? 'success' : 'failure'}</li>
            ))}
          </ul>
        </div>

        {/* Right: Actions */}
        <div className="grid grid-flow-col sm:auto-cols-max justify-start sm:justify-end gap-2">

          <div>
            All Classes: {allClasses}
          </div>
          <div>
            Parsed: {stage1Success}
          </div>
          <div>
            C Generated: {stage2Success}
          </div>
          <div>
            C Compiled: {stage3Success}
          </div>
          <div>
            Symbolic Execution Checked: {stage4Success}
          </div>
        </div>

      </div>

      {/* Table */}
      <TestcaseTable testcases={t} />
    </div>
  )
}

export default function Customers() {
  return (
    <SelectedItemsProvider>
      <CustomersContent />
    </SelectedItemsProvider>
  )
}
