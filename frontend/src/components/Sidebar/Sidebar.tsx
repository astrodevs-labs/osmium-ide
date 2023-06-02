import Icon from '../Icon/Icon';
import React, { FC } from 'react';

interface SideBarProps {
  children: React.ReactNode;
}

const Sidebar: FC<SideBarProps> = ({ children }) => {
  return (
    <div className="h-full flex fixed bg-amber-400">
      <div className="flex-col bg-osmium-error">
        {children &&
          children
            // @ts-ignore
            .filter((child) => child.props.node.type === 'sidebar-item')}
      </div>
      <div className="flex-col bg-blue-500">
        {children &&
          children
            // @ts-ignore
            .filter((child) => child.props.node.type === 'sidebar-panel')}
      </div>
    </div>
  );
};

export default Sidebar;
