import { LeftBarProps } from './LeftBar.types';
import Icon from '../Icon/Icon';
import { useState } from 'react';


const LeftBar: React.FC<LeftBarProps> = () => {
  const [iconselected, setiIconselected] = useState<string>('document');
  return (
    <div className='h-full bg-white-300 text-white'>
      <div className='flex' onClick={() => setiIconselected('document')}>
        {iconselected == 'document' &&
          <div className='bg-[#3C9DA1] h-100 w-2'>

          </div>
        }
        <Icon icon={'document'} size={64} stroke="#999999" viewBox="0 0 24 24" fill='none'></Icon>
      </div>


      <div className='flex' onClick={() => setiIconselected('zoom')}>
        {iconselected == 'zoom' &&
          <div className='bg-[#3C9DA1] h-100 w-2'>

          </div>
        }
        <Icon icon={'zoom'} size={64} stroke="#999999" viewBox="0 0 24 24" ></Icon>
      </div>


      {/* <svg viewBox="0 0 24 24" fill="none">
        <path
          stroke="#999999" stroke-width="1.5" stroke-linecap="round" stroke-linejoin="round"
          d="M8 13H14M8 17H16M13 3H5V21H19V9M13 3H14L19 8V9M13 3V7C13 8 14 9 15 9H19"
        ></path>
      </svg>



      <svg viewBox="0 0 24 24" fill="none">
        <path fill-rule="evenodd" clip-rule="evenodd" fill="#999999"
          d="M4 11C4 7.13401 7.13401 4 11 4C14.866 4 18 7.13401 18 11C18 14.866 14.866 18 11 18C7.13401 18 4 14.866 4 11ZM11 2C6.02944 2 2 6.02944 2 11C2 15.9706 6.02944 20 11 20C13.125 20 15.078 19.2635 16.6177 18.0319L20.2929 21.7071C20.6834 22.0976 21.3166 22.0976 21.7071 21.7071C22.0976 21.3166 22.0976 20.6834 21.7071 20.2929L18.0319 16.6177C19.2635 15.078 20 13.125 20 11C20 6.02944 15.9706 2 11 2Z"
        ></path>
      </svg> */}
    </div>
  )
}

export default LeftBar;