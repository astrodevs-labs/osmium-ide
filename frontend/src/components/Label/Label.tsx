import React from 'react';
import './Label.css';
import { LabelProps } from './Label.types';

const Label: React.FC<LabelProps> = ({ label, onLabelClick }) => {
  return (
    <label className="label__input" onClick={onLabelClick}>
      {label}
    </label>
  );
};

export default Label;
