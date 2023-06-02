import { FC } from 'react';

interface EditorProps {
  content: string;
}

const Editor: FC<EditorProps> = ({ content }) => {
  const b64ToStr = (b64: string) => {
    return atob(b64);
  };

  return <textarea className="w-full h-full bg-transparent text-white outline-none p-2">{b64ToStr(content)}</textarea>;
};

export default Editor;
