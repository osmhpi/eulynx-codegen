import Link from 'next/link'
import Image, { StaticImageData } from 'next/image'

interface Job {
  key: string,
  parsing: string[],
  compilation: string[],
  checks: string[],
  total: string[]
}

export default function JobsItem({ job }: { job: Job }) {
  return (
    <div
      className={`shadow-lg rounded-sm border px-5 py-4 bg-white dark:bg-slate-800`}
    >
      <div className="md:flex justify-between items-center space-y-4 md:space-y-0 space-x-2">
        <div className="flex items-start space-x-3 md:space-x-4">
          <div>
            <span className="inline-flex font-semibold text-slate-800 dark:text-slate-100">
              {job.key}
            </span>
            <div className="text-sm">
              <span title={job.parsing.join(', ')}>Parsing: {job.parsing.length}</span> / <span title={job.compilation.join(', ')}>Compilation: {job.compilation.length}</span> / <span title={job.checks.join(', ')}>Checks: {job.checks.length}</span> / <span title={job.total.join(', ')}>Total: {job.total.length}</span>
            </div>
          </div>
        </div>
      </div>
    </div>
  )
}
