import Icon from '../Icon/Icon';
import React, { FC } from 'react';

interface SideBarProps {
  children?: React.ReactNode;
}

const Sidebar: FC<SideBarProps> = ({ children }) => {
  return <div className="h-full fixed flex-col">{children}</div>;
};

export default Sidebar;
