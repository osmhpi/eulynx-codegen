/** @type {import('next').NextConfig} */
const nextConfig = {
  webpack: (config, { defaultLoaders }) => {
    config.module.rules.push({
      test: /\.xml$/,
      use: [ { loader: 'xml-loader' } ],
    })

    return config
  }
}

module.exports = nextConfig
