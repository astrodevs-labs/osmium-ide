import Icon from '../Icon/Icon';
import React, { FC, useState } from 'react';

interface SidebarItemProps {
  title: string;
  icon: string;
  selected?: boolean;
}

const SidebarItem: FC<SidebarItemProps> = ({ title, icon, selected }) => {
  const [hover, setHover] = useState<boolean>(false);

  return (
    <div className="flex" onMouseOver={() => setHover(true)} onMouseOut={() => setHover(false)}>
      <div className={'h-100 w-1 ' + (selected ? 'bg-osmium-primary' : hover && 'bg-osmium-bgLight')} />
      <Icon icon={icon} size={64} stroke="#999999" viewBox="0 0 24 24" fill="none" />
    </div>
  );
};

export default SidebarItem;
