import './Button.css';
import React from "react";
import {ButtonProps} from "./Button.types";

const Button: React.FC<ButtonProps> = ({onClick, disabled, children}) => {
    return (
        <button
            className={disabled ? "button disabled" : "button"}
            onClick={onClick}
            disabled={disabled}
        >
            {children}
        </button>
    );
};

export default Button;