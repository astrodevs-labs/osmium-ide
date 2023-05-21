import React from 'react';
import { TextAreaProps } from './TextArea.types';

const TextArea: React.FC<TextAreaProps> = ({ content, setContent }) => {
  return (
    <textarea
      onChange={(e) => { setContent(e.target.value) }}
      className="resize-none w-full h-full bg-gray-800 text-white font-mono text-sm p-2" >
      {content}
    </textarea>
  );
}


export default TextArea;