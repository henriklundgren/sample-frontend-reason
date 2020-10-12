const withTM = require('next-transpile-modules')(['bs-platform', '@jsiebern/bs-material-ui'])
const debug = process.env.NODE_ENV !== 'production'

module.exports = withTM({
  pageExtensions: ['jsx', 'js', 'bs.js'],
  generateBuildId: async () => 'current',
  assetPrefix: !debug ? '/sample-frontend-reason' : '',
});

