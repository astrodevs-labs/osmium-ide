import { FC, useState } from 'react';
import { Tab } from '../Components';
import { TabsBarProps } from './TabsBar.types';

const TabsBar: FC<TabsBarProps> = ({ fileList }) => {
  const [activeTab, setActiveTab] = useState<number>();
  return (
    <div className="flex overflow-y-auto scrollbar">
      {fileList.map((file: string, index) => {
        return <Tab file={file} active={index === activeTab} onClick={() => setActiveTab(index)} />;
      })}
    </div>
  );
};

export default TabsBar;
