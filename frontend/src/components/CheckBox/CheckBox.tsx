import React, { useState } from 'react';
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
    <input
      className="checkbox__input"
      type="checkbox"
      id={label}
      checked={isChecked}
      disabled={isDisabled}
      onChange={(event) => {
        setIsChecked(!isChecked);
        onCheckboxChange && onCheckboxChange(event);
        console.log('onChange');
      }}
      onClick={onCheckboxClick}
      onFocus={onCheckboxFocus}
      onBlur={onCheckboxBlur}
    />
  );
};

export default CheckBox;
