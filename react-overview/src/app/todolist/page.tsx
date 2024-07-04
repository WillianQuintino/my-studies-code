"use client"

import { stringify } from "querystring";
import { ReactNode, useEffect, useState } from "react";
import { ButtonMainAdd, ButtonCopy, ButtonRemove, ButtonUpdate } from "../components/todolist/Buttons";

export interface IList {
    id:number,
    text:string,
    checked:boolean,
    child?:IList[]
}

let arrayList:IList[] = [];

interface IModalBottom {
    children:ReactNode
}

const ModalList:React.FC<{items: IList[] }> = ({items}) => {
    return (
        <>
        <ul className="w-1/2">
        {items.map((item) => (
            <>
            <ItemList key={item.id} item={item} />
            </>
        ))}
        <ButtonMainAdd />
        </ul>
        </>
    );
}

const ItemList: React.FC<{ item: IList }> = ({ item }) => {
    const [checked, setChecked] = useState(false);
    const [inputEnable, setCheckedInput] = useState(false);
    const [inputValue, setInputValue] = useState(item.text);

    const handleCheckboxChange = () => {
        setChecked(!checked);
        item.checked = checked;
    };

    const handleInputChange = () => {
        setCheckedInput(!inputEnable);
    };

    useEffect(()=>{
        console.log(inputEnable);
    }, [inputEnable]);
  
    const handleTextChange = (event: React.ChangeEvent<HTMLInputElement>) => {
        setInputValue(event.target.value);
        item.text = event.target.value;
    };

    return (
        <>
        <li style={{ textDecoration: item.checked ? 'line-through' : 'none' }}>
            <div className="w-full flex flex-row justify-between">
                <div>
                    <input type="checkbox" name={"checkbox-"+String(item.id)} id={"checkbox-"+String(item.id)} checked={item.checked} onChange={handleCheckboxChange}/> 
                    {inputEnable === true ? (
                        <input 
                            type="text" 
                            name={"input-"+String(item.id)} 
                            id={"input-"+String(item.id)} 
                            value={inputValue} 
                            onChange={handleTextChange} /> 
                    ) : (
                        <button onClick={handleInputChange} >{item.text}</button>
                    )
                    }
                </div>
                <div>
                    {inputEnable && (
                        <ButtonUpdate 
                            checkedInputId={item.id} 
                            checkedInputI={inputEnable} 
                            setCheckedInputI={handleInputChange} 
                            arrayList={arrayList}
                            />)}
                    <ButtonCopy id={item.id} />
                    <ButtonRemove id={item.id} />
                </div>    
            </div>
        {item.child && item.child.length > 0 && (
            <ul>
                {item.child.map((childItem)=>(
                    <ItemList key={childItem.id} item={childItem} />
                ))}
            </ul>
        )}
        </li>
        </>
    );
}

let list: IList[] = [
  {
    id: 1,
    text: '1.',
    checked: false,
    child: [
      {
        id: 4,
        text: '1.1.',
        checked: true,
        child: [
            {
                id: 5,
                text: '1.1.1.',
                checked: true
            }
        ]
      }
    ]
  },
  {
    id: 2,
    text: '2.',
    checked: false,
  },
  {
    id: 3,
    text: '3.',
    checked: false,
  }
];

export default function Page() {
    const localData = localStorage.getItem('Local');

    if(localData){
      arrayList =  JSON.parse(localData);
    }
    
    return (
        <>
        <div className="w-full flex flex-col items-center">
            <h1>Todo List</h1>
            <ModalList items={list} />
        </div>
        </>
    );
}
