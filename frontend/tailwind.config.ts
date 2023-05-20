/** @type {import('tailwindcss').Config} */
export default {
  content: [
    "./index.html",
    "./src/**/*.{js,ts,jsx,tsx}",
  ],
  theme: {
    extend: {
      colors: {
        'osmium-grey': '#999999',
        'osmium-primary': '#3C9DA1'
      },},
  },
  plugins: [],
}

