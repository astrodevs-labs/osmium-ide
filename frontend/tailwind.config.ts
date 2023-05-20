/** @type {import('tailwindcss').Config} */
export default {
  content: [
    "./index.html",
    "./src/**/*.{js,ts,jsx,tsx}",
  ],
  theme: {
    extend: {
      colors: {
        'osmium-bg': '#161C22',
        'osmium-bgLight': '#3E4E5C',
        'osmium-bgCode': '#1A1E25',
        'osmium-primary': '#3C9DA1',
        'osmium-secondary': '#183454',
        'osmium-border': '#151A1F',
        'osmium-text': '#E6E6E6',
        'osmium-warning': '#C58200',
        'osmium-error': '#8E0000',
        'osmium-sucess': '#009E10',
        'osmium-grey': '#999999',
      },},
  },
  plugins: [],
}

