import React, { SyntheticEvent, useState } from 'react';
import { FolderProps } from './Folder.types';
import { Icon } from '../Components';

const Folder: React.FC<FolderProps> = ({ name, isFolder, items }) => {
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
      if (!isFolder) console.log('dispatch event');
      return;
    }
  };

  return (
    <div className="text-white">
      <div className="flex items-center space-x-2 cursor-default border border-sky-500" onClick={handleDoubleClick}>
        <div onClick={handleClick}>
          {isFolder && <Icon viewBox='0 0 1024 1024' icon={expand ? 'arrow-down' : 'arrow-right'} size={16} fill="white" />}
        </div>
        <h2 className={(isFolder ? '' : 'pl-2') + ' select-none'}>{name}</h2>
      </div>
      <div className={(expand ? 'block' : 'hidden') + ' pl-4'}>
        {items.map((sub) => (
          <Folder name={sub.name} isFolder={sub.isFolder} items={sub.items} key={sub.name} />
        ))}
      </div>
    </div>
  );
};

export default Folder;
