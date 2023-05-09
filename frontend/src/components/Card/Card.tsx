import React from 'react';
import { CardProps } from './Card.types';

const Card: React.FC<CardProps> = ({ children, className, onClick, disabled, visible = true, title, subtitle }) => {
  return (
    <div
      className={
        'bg-blue-800 text-white font-bold py-2 px-4 rounded' +
        (disabled ? 'cursor-not-allowed opacity-50 bg-gray-500' : ' hover:bg-blue-600') +
        ' ' +
        className
      }
      onClick={disabled ? undefined : onClick}
      style={{ display: visible ? 'block' : 'none' }}
    >
      {title && (
        <>
          <div className="text-2xl underline">{title}</div>
        </>
      )}
      {subtitle && <div className="text-xl">{subtitle}</div>}
      {children}
    </div>
  );
};

export default Card;
