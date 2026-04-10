/** @type {import('next').NextConfig} */
const nextConfig = {
  output: 'export',
  trailingSlash: true,
  basePath: process.env.BASE_PATH || '',
  webpack: (config, { defaultLoaders }) => {
    config.module.rules.push({
      test: /\.xml$/,
      use: [ { loader: 'xml-loader' } ],
    })

    return config
  }
}

module.exports = nextConfig
