import React from 'react';
import { ButtonProps } from './Button.types';

const Button: React.FC<ButtonProps> = ({ onClick, disabled, children }) => {
  return (
    <button
      className={
        'bg-blue-800 text-white font-bold py-2 px-4 rounded ' +
        (disabled ? 'cursor-not-allowed opacity-50 bg-blue-500' : ' hover:bg-blue-600')
      }
      onClick={onClick}
      disabled={disabled}
    >
      {children}
    </button>
  );
};

export default Button;
