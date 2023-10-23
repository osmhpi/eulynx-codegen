declare module "*.xml" {
  const content: {
    testsuites: {
      testsuite: {
        '$': {
          name: string,
          tests: string,
          skipped: string,
          failures: string,
          errors: string,
          time: string,
          timestamp: string,
          hostname: string,
          id: string,
          package: string
        },
        testcase: {
          '$': {
            classname: string,
            name: string,
            time: string
          },
          failure?: {
            '_': string,
            '$': {
              type: string,
              message: string
            }
          }[]
        }[]
      }[]
    }
  }
  export default content;
}
