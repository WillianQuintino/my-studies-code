"use client"

import { ReactNode, useState } from "react";

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
        </ul>
        </>
    );
}

const ItemList: React.FC<{ item: IList }> = ({ item }) => {
    const [checked, setChecked] = useState(false);
    const [inputEnable, setCheckedInput] = useState(false);

    const handleCheckboxChange = () => {
        setChecked(!checked);
        item.checked = checked;
    };

    const handleInputChange = () => {
        setCheckedInput(!inputEnable);
        console.log(inputEnable);
    };
  
    return (
        <>
        <li style={{ textDecoration: item.checked ? 'line-through' : 'none' }}>
            <div className="w-full flex flex-row justify-between">
                <div>
                    <input type="checkbox" name={"checkbox-"+String(item.id)} id={"checkbox-"+String(item.id)} checked={item.checked} onChange={handleCheckboxChange}/> 
                    {inputEnable ? (
                        <>
                        <input type="text" name={"input-"+String(item.id)} id={"input-"+String(item.id)} value={item.text} /> 
                        <button onChange={handleInputChange} >{item.text}</button>
                        </>
                        ) : (
                        <button onChange={handleInputChange} >{item.text}</button>
                    )
                    }
                </div>
                <div>
                    <BottomCopy id={item.id} />
                    <BottomRemove id={item.id} />
                </div>    
            </div>
        {item.child && item.child.length > 0 && (
            <ul>
                {item.child.map((childItem)=>(
                    <>
                    <ItemList key={childItem.id} item={childItem} />
                    </>
                ))}
            </ul>
        )}
        </li>
        </>
    );
}

const BottomRemove: React.FC<{id: number}> = ({id}) => {
    return (
        <>
        <button>
            <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 24" fill="currentColor" className="size-6">
                <path fillRule="evenodd" d="M16.5 4.478v.227a48.816 48.816 0 0 1 3.878.512.75.75 0 1 1-.256 1.478l-.209-.035-1.005 13.07a3 3 0 0 1-2.991 2.77H8.084a3 3 0 0 1-2.991-2.77L4.087 6.66l-.209.035a.75.75 0 0 1-.256-1.478A48.567 48.567 0 0 1 7.5 4.705v-.227c0-1.564 1.213-2.9 2.816-2.951a52.662 52.662 0 0 1 3.369 0c1.603.051 2.815 1.387 2.815 2.951Zm-6.136-1.452a51.196 51.196 0 0 1 3.273 0C14.39 3.05 15 3.684 15 4.478v.113a49.488 49.488 0 0 0-6 0v-.113c0-.794.609-1.428 1.364-1.452Zm-.355 5.945a.75.75 0 1 0-1.5.058l.347 9a.75.75 0 1 0 1.499-.058l-.346-9Zm5.48.058a.75.75 0 1 0-1.498-.058l-.347 9a.75.75 0 0 0 1.5.058l.345-9Z" clipRule="evenodd" />
            </svg>
        </button>
        </>
    );
}

const BottomCopy: React.FC<{id: number}> = ({id}) => {
    return (
        <>
        <button>
            <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 24" fill="currentColor" className="size-6">
                <path fillRule="evenodd" d="M7.502 6h7.128A3.375 3.375 0 0 1 18 9.375v9.375a3 3 0 0 0 3-3V6.108c0-1.505-1.125-2.811-2.664-2.94a48.972 48.972 0 0 0-.673-.05A3 3 0 0 0 15 1.5h-1.5a3 3 0 0 0-2.663 1.618c-.225.015-.45.032-.673.05C8.662 3.295 7.554 4.542 7.502 6ZM13.5 3A1.5 1.5 0 0 0 12 4.5h4.5A1.5 1.5 0 0 0 15 3h-1.5Z" clipRule="evenodd" />
                <path fillRule="evenodd" d="M3 9.375C3 8.339 3.84 7.5 4.875 7.5h9.75c1.036 0 1.875.84 1.875 1.875v11.25c0 1.035-.84 1.875-1.875 1.875h-9.75A1.875 1.875 0 0 1 3 20.625V9.375ZM6 12a.75.75 0 0 1 .75-.75h.008a.75.75 0 0 1 .75.75v.008a.75.75 0 0 1-.75.75H6.75a.75.75 0 0 1-.75-.75V12Zm2.25 0a.75.75 0 0 1 .75-.75h3.75a.75.75 0 0 1 0 1.5H9a.75.75 0 0 1-.75-.75ZM6 15a.75.75 0 0 1 .75-.75h.008a.75.75 0 0 1 .75.75v.008a.75.75 0 0 1-.75.75H6.75a.75.75 0 0 1-.75-.75V15Zm2.25 0a.75.75 0 0 1 .75-.75h3.75a.75.75 0 0 1 0 1.5H9a.75.75 0 0 1-.75-.75ZM6 18a.75.75 0 0 1 .75-.75h.008a.75.75 0 0 1 .75.75v.008a.75.75 0 0 1-.75.75H6.75a.75.75 0 0 1-.75-.75V18Zm2.25 0a.75.75 0 0 1 .75-.75h3.75a.75.75 0 0 1 0 1.5H9a.75.75 0 0 1-.75-.75Z" clipRule="evenodd" />
            </svg>
        </button>
        </>
    );
}

interface IList {
    id:number,
    text:string,
    checked:boolean,
    child?:IList[]
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
    return (
        <>
        <div className="w-full flex flex-col items-center">
            <h1>Todo List</h1>
            <ModalList items={list} />
        </div>
        </>
    );
}
