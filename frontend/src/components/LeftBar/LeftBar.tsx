import Icon from '../Icon/Icon';
import React, { useState } from 'react';

const LeftBar = () => {
  const [selectedIcon, setSelectedIcon] = useState<string>('document');
  return (
    <div className="h-full text-white">
      <div className="flex" onClick={() => setSelectedIcon('document')}>
        <div className={(selectedIcon === 'document' ? 'bg-osmium-primary ' : '') + 'h-100 w-1'}></div>
        <Icon icon={'document'} size={64} stroke="#999999" viewBox="0 0 24 24" fill="none"></Icon>
      </div>
      <div className="flex" onClick={() => setSelectedIcon('zoom')}>
        <div className={(selectedIcon === 'zoom' ? 'bg-osmium-primary ' : '') + 'h-100 w-1'}></div>
        <Icon icon={'zoom'} size={64} fill="#999999" viewBox="0 0 24 24"></Icon>
      </div>
    </div>
  );
};

export default LeftBar;
