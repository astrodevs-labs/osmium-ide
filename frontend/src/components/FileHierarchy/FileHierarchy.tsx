import React, { FC, useState } from 'react';
import { Icon } from '../Components';

interface Item {
  name: string;
  type: string;
  items?: Item[];
}

interface FileHierarchyProps {
  files: Item[];
}

const File: React.FC<Item> = ({ name, type, items }) => {
  const [expand, setExpand] = useState<boolean>(false);

  const handleClick = (e: React.MouseEvent<HTMLElement>) => {
    if (e.detail === 1) {
      setExpand(!expand);
      return;
    }
  };

  const handleDoubleClick = (e: React.MouseEvent<HTMLElement>) => {
    if (e.detail === 2) {
      setExpand(!expand);
      if (type !== 'folder') console.log('dispatch event');
      return;
    }
  };

  return (
    <div className="text-white">
      <div className="flex items-center space-x-2 cursor-default" onClick={handleDoubleClick}>
        <div onClick={handleClick}>
          {type === 'folder' && (
            <Icon viewBox="0 0 1024 1024" icon={expand ? 'arrow-down' : 'arrow-right'} size={16} fill="white" />
          )}
        </div>
        <h2 className={(type === 'folder' ? '' : 'pl-2') + ' select-none'}>{name}</h2>
      </div>
      <div className={(expand ? 'block' : 'hidden') + ' pl-4'}>
        {items?.map((sub) => (
          <File name={sub.name} type={sub.type} items={sub.items} key={sub.name} />
        ))}
      </div>
    </div>
  );
};

const FileHierarchy: FC<FileHierarchyProps> = ({ files }) => {
  return (
    <>
      {files.map((file) => (
        <File name={file.name} type={file.type} items={file.items} key={file.name} />
      ))}
    </>
  );
};

export default FileHierarchy;
