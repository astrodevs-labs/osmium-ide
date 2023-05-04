import './App.css';
import Toolbar from './components/Toolbar/Toolbar';
import { useState } from 'react';

const App = () => {
  const [content, setContent] = useState<string>('');
  return (
    <div className="container">
      <Toolbar content={content} setContent={setContent} />
      <textarea
        onChange={(event) => {
          setContent(event.target.value);
        }}
        className="textarea"
        value={content}
      ></textarea>
    </div>
  );
};

export default App;
