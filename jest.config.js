module.exports = {
  testMatch: ['<rootDir>/lib/**/__tests__/*_test.bs.js'],
  transformIgnorePatterns: [],
  transform: {
    '^.+\\.jsx?$': 'babel-jest',
  },
}
