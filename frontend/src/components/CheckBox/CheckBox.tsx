import React, { useState } from 'react';
import Label from '../Label/Label';
import './CheckBox.css';
import { CheckBoxProps } from './CheckBox.types';

const CheckBox: React.FC<CheckBoxProps> = ({
  label,
  checked = false,
  disabled = false,
  onCheckboxChange,
  onCheckboxClick,
  onCheckboxFocus,
  onCheckboxBlur,
}) => {
  const [isChecked, setIsChecked] = useState(checked);
  const [isDisabled, setIsDisabled] = useState(disabled);

  return (
    <div className="checkbox__container">
      <input
        className="checkbox__input"
        type="checkbox"
        id={label}
        checked={isChecked}
        disabled={isDisabled}
        onChange={(event) => {
          setIsChecked(!isChecked);
          onCheckboxChange && onCheckboxChange(event);
        }}
        onClick={onCheckboxClick}
        onFocus={onCheckboxFocus}
        onBlur={onCheckboxBlur}
      />
    </div>
  );
};

export default CheckBox;
