import { useState } from 'react';
import { SwitchProps } from './Switch.types';

const Switch: React.FC<SwitchProps> = ({ onClick, disabled }) => {
  const [switchSate, setSwitchSate] = useState(false);

  return (
    <svg
      className={`${switchSate ? `fill-osmium-bgLight rotate-180` : 'fill-osmium-primary'} hover:fill-white`}
      width="64"
      height="64"
      viewBox="0 0 32 32"
      onClick={() => {
        setSwitchSate(!switchSate);
        onClick();
      }}
    >
      <g fillRule="evenodd">
        <path d="m22 6c5.5228475 0 10 4.4771525 10 10s-4.4771525 10-10 10h-12c-5.5228475 0-10-4.4771525-10-10s4.4771525-10 10-10zm0 4c-3.3137085 0-6 2.6862915-6 6s2.6862915 6 6 6 6-2.6862915 6-6-2.6862915-6-6-6z" />
      </g>
    </svg>
  );
};

export default Switch;
