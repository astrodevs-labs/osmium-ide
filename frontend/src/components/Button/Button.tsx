import React from 'react';
import { ButtonProps } from './Button.types';

const Button: React.FC<ButtonProps> = ({ onClick, disabled, children = undefined, className, value = undefined }) => {
  return (
    <button
      className={
        'bg-blue-800 text-white font-bold py-2 px-4 rounded ' +
        (disabled ? 'cursor-not-allowed opacity-50 bg-gray-500' : ' hover:bg-gray-600') +
        ' ' +
        className
      }
      onClick={onClick}
      disabled={disabled}
      value={value}
    >
      {value || children}
    </button>
  );
};

export default Button;
