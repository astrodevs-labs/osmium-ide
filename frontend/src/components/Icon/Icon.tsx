import { IconProps } from './Icon.types';

const icons: any = {
  'arrow-left': 'M512 64L64 512l448 448 64-64L192 512l384-384z',
  'arrow-right': 'M512 960L960 512 512 64 448 128l384 384-384 384z',
  'arrow-up': 'M960 512L512 64 64 512l128 128 192-192v576h256V448l192 192z',
  'arrow-down': 'M64 512l448 448 448-448-64-64-384 384L128 448z',
};
const Icon = (props: IconProps) => {
  return (
    <svg width={props.size} height={props.size} viewBox="0 0 1024 1024">
      <path fill={props.color} d={icons[props.icon]}></path>
    </svg>
  );
};

export default Icon;
