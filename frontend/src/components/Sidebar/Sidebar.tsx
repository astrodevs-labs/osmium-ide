import React, { FC } from 'react';

interface SideBarProps {
  children: React.ReactNode;
}

const Sidebar: FC<SideBarProps> = ({ children }) => {
  return (
    <div className="h-full flex">
      <div className="flex-col border-r border-osmium-bgLight">
        {children &&
          children
            // @ts-ignore
            .filter((child) => child.props.node.type === 'sidebar-item')}
      </div>
      {children &&
        children
          // @ts-ignore
          .filter((child) => child.props.node.type === 'sidebar-panel')}
    </div>
  );
};

export default Sidebar;
