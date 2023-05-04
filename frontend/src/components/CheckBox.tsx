import React, {useState} from 'react';
import Label from "./Label";

interface CheckBoxProps {
  label: string;
  checked: boolean;
  disabled?: boolean;
  onCheckboxChange?: (event: React.ChangeEvent<HTMLInputElement>) => void;
  onCheckboxClick?: (event: React.MouseEvent<HTMLInputElement>) => void;
  onCheckboxFocus?: (event: React.FocusEvent<HTMLInputElement>) => void;
  onCheckboxBlur?: (event: React.FocusEvent<HTMLInputElement>) => void;
}

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
    // let's create our own checkbox component
    <div className={'checkbox__container'}>
      <input
        className={'checkbox__input'}
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
      <Label label={label} />
    </div>
  );
};

export default CheckBox;
