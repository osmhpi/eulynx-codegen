'use client'

import { useItemSelection } from '@/components/utils/use-item-selection'
import TestcaseTableItem from './testcase-table-item'

export interface Testcase {
  class: string,
  package: string,
  tests: {
    testname: string,
    failure?: {
      '_': string,
      '$': {
        type: string,
        message: string
      }
    }[],
    skipped?: {}[]
  }[],
}

export default function TestcaseTable({ testcases }: { testcases: Testcase[]}) {
  const {
    selectedItems,
    isAllSelected,
    handleCheckboxChange,
    handleSelectAllChange,
  } = useItemSelection(testcases)

  return (
    <div className="bg-white dark:bg-slate-800 shadow-lg rounded-sm border border-slate-200 dark:border-slate-700 relative">
      <header className="px-5 py-4">
        <h2 className="font-semibold text-slate-800 dark:text-slate-100">All Customers <span className="text-slate-400 dark:text-slate-500 font-medium">248</span></h2>
      </header>
      <div>

        {/* Table */}
        <div className="overflow-x-auto">
          <table className="table-auto w-full dark:text-slate-300">
            {/* Table header */}
            <thead className="text-xs font-semibold uppercase text-slate-500 dark:text-slate-400 bg-slate-50 dark:bg-slate-900/20 border-t border-b border-slate-200 dark:border-slate-700">
              <tr>
                <th className="px-2 first:pl-5 last:pr-5 py-3 whitespace-nowrap w-px">
                  <div className="flex items-center">
                    <label className="inline-flex">
                      <span className="sr-only">Select all</span>
                      <input className="form-checkbox" type="checkbox" onChange={handleSelectAllChange} checked={isAllSelected} />
                    </label>
                  </div>
                </th>
                <th className="px-2 first:pl-5 last:pr-5 py-3 whitespace-nowrap">
                  <div className="font-semibold text-left">Package</div>
                </th>
                <th className="px-2 first:pl-5 last:pr-5 py-3 whitespace-nowrap">
                  <div className="font-semibold text-left">Class</div>
                </th>
                <th className="px-2 first:pl-5 last:pr-5 py-3 whitespace-nowrap">
                  <span className="sr-only">Menu</span>
                </th>
              </tr>
            </thead>
            {/* Table body */}
            <tbody className="text-sm divide-y divide-slate-200 dark:divide-slate-700">
              {testcases.map(testcase => (
                <TestcaseTableItem
                  key={`${testcase.package}-${testcase.class}`}
                  testcase={testcase}
                  onCheckboxChange={handleCheckboxChange}
                  isSelected={false} />
              ))}
            </tbody>
          </table>

        </div>
      </div>
    </div>
  )
}
