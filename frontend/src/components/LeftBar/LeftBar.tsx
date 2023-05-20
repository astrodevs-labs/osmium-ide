import { LeftBarProps } from './LeftBar.types';
import Icon from '../Icon/Icon';
import { useState } from 'react';

const LeftBar: React.FC<LeftBarProps> = () => {
  const [iconselected, setiIconselected] = useState<string>('document');
  return (
    <div className="h-full bg-white-300 text-white">
      <div className="flex" onClick={() => setiIconselected('document')}>
        <div className={(iconselected == 'document' ? "bg-osmium-primary " : "") + "h-100 w-1"}></div>
        <Icon icon={'document'} size={64} stroke="#999999" viewBox="0 0 24 24" fill="none"></Icon>
      </div>

      <div className="flex" onClick={() => setiIconselected('zoom')}>
        <div className={(iconselected == 'zoom' ? "bg-osmium-primary " : "") + "h-100 w-1"}></div>
        <Icon icon={'zoom'} size={64} fill="#999999" viewBox="0 0 24 24"></Icon>
      </div>
    </div>
  );
};

export default LeftBar;
