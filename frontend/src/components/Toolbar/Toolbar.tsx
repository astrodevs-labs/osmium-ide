import Button from '../Button/Button';
import './Toolbar.css';
import React, { useState } from 'react';
import { ToolbarProps } from './Toolbar.types';
import { BaseDirectory, readTextFile, writeTextFile } from '@tauri-apps/api/fs';

const Toolbar: React.FC<ToolbarProps> = ({ content, setContent }) => {
  const [path, setPath] = useState<string>('');
  const openFile = async () => {
    const pathContent = await readTextFile(path);
    setContent(pathContent);
    console.log('open file');
  };

  const saveFile = () => {
    writeTextFile(path, content);
    console.log('save file');
  };

  return (
    <div className="toolbar">
      <div>
        <Button onClick={openFile}>Open file</Button>
        <input
          onChange={(event) => {
            setPath(event.target.value);
          }}
        />
      </div>
      <Button onClick={saveFile}>Save file</Button>
    </div>
  );
};

export default Toolbar;
