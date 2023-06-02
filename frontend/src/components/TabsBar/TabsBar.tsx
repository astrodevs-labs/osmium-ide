import React, { FC } from 'react';

interface TabsBarProps {
  children?: React.ReactNode;
}

const TabsBar: FC<TabsBarProps> = ({ children }) => {
  return <div className="flex overflow-y-auto scrollbar">{children}</div>;
};

export default TabsBar;
