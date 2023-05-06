import Toolbar from './components/Toolbar/Toolbar';
import { useState } from 'react';

const App = () => {
  const [content, setContent] = useState<string>('');
  return (
    <div className="w-full h-screen">
      <Toolbar content={content} setContent={setContent} />
      <textarea
        onChange={(event) => {
          setContent(event.target.value);
        }}
        className="border-gray-900 text-xl w-full bg-gray-900 text-gray-300"
        value={content}
      ></textarea>
    </div>
  );
};

export default App;
