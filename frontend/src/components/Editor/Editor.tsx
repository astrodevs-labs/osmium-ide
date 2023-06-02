import { FC } from 'react';

interface EditorProps {
  content: string;
}

const Editor: FC<EditorProps> = ({ content }) => {
  return <textarea className="w-full h-full bg-transparent text-white outline-none p-2">{content}</textarea>;
};

export default Editor;
