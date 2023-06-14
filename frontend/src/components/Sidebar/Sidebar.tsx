import React, { FC } from 'react';

interface SideBarProps {
  children: React.ReactNode;
}

const Sidebar: FC<any> = (props) => {
  const { children } = props;
  console.log("children", children);
  console.log("props", props)
  return (
    <div className="h-full flex">
      <div className="flex-col border-r border-osmium-bgLight">
        {children &&
          children
            // @ts-ignore
            .filter((child) => child.props.component?.type === 'sidebar-item')}
      </div>
      {children &&
        children
          // @ts-ignore
          .filter((child) => child.props.component?.type === 'sidebar-panel')}
    </div>
  );
};

export default Sidebar;
