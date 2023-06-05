import React, { FC } from 'react';

interface SidebarPanelProps {
  children?: React.ReactNode;
  expanded: boolean;
}

const SidebarPanel: FC<SidebarPanelProps> = ({ children, expanded }) => {
  return <div className="flex-col border-r border-osmium-bgLight p-2 min-w-fit">{expanded && children}</div>;
};

export default SidebarPanel;
