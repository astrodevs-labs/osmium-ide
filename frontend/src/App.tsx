import "./App.css";
import CheckBox from "./components/CheckBox";
import Label from "./components/Label";

function App() {
  return (
    <div className="container">
      <div className="row">
        <Label label={'test'} />
        <br/>
        <CheckBox
          label={'test'}
          checked={true}
          disabled={false}
        />
      </div>
    </div>
  );
}

export default App;
