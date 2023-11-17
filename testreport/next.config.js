/** @type {import('next').NextConfig} */
const nextConfig = {
  output: 'export',
  trailingSlash: true,
  basePath: '/system-model-validation',
  assetPrefix: '/system-model-validation/',
  webpack: (config, { defaultLoaders }) => {
    config.module.rules.push({
      test: /\.xml$/,
      use: [ { loader: 'xml-loader' } ],
    })

    return config
  }
}

module.exports = nextConfig
