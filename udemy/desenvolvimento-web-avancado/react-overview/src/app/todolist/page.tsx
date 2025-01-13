"use client"

import { ReactNode, useState } from "react";
import { ButtonMainAdd, ButtonCopy, ButtonRemove, ButtonUpdate, ButtonAdd, updateItem, listItem } from "../components/todolist/Buttons";
import { ItemProvider, useItem } from "../context/arrayList";


export interface IList {
    id:number,
    text:string,
    checked:boolean,
    father:number,
    child?:IList[]
}

const ModalList:React.FC = () => {
    const{arrayList}=useItem();

    return (
        <>
        <ul className="w-1/2 m-5 p-2 bg-white rounded-2xl">
        {arrayList.map((item) => (
            <>
            <ItemList key={item.id} item={item} />
            </>
        ))}
        <ButtonMainAdd />
        </ul>
        </>
    );
}

const ItemList: React.FC<{ item: IList}> = ({ item }) => {
    const {arrayList, setArrayList}=useItem();
    const [checked, setChecked] = useState(!item.checked);
    const [inputEnable, setCheckedInput] = useState(false);
    const [inputValue, setInputValue] = useState(item.text);

    function checkFather (id: number, ): void {
        let fatherId = listItem(arrayList, id)?.father;
        let fatherItem = (fatherId) && listItem(arrayList, fatherId);
        if(fatherItem){
            let checkedFather = true;
            fatherItem.child?.map((item) => {
                if(!item.checked) checkedFather = false;
            })
            fatherItem.checked = checkedFather;
            if(fatherId !== undefined) {
                setArrayList(updateItem(arrayList, fatherId, fatherItem));
                if(fatherItem.father !== 0) checkFather(fatherId);
            }
        }
    }

    const handleCheckboxChange = () => {
        setChecked(!checked);
        item.checked = checked;
        setArrayList(updateItem(arrayList, item.id, undefined, undefined, checked));
        checkFather(item.id);
    };

    const handleInputChange = () => {
        setCheckedInput(!inputEnable);
    };

    const handleAddList = () => {
        if (inputValue.trim() !== '') {
            const newItem: IList = {
                id: item.id,
                text: inputValue.trim(),
                checked: false,
                father: item.father
            };
            setArrayList(updateItem(arrayList, item.id, newItem));
            handleInputChange();
        }
    };

    const handleTextChange = (event: React.ChangeEvent<HTMLInputElement>) => {
        setInputValue(event.target.value);
        item.text = event.target.value;
    };

    const handleKeyDownTextEvent = (event: React.KeyboardEvent<HTMLInputElement>) => {   
        if(event.key === 'Enter'){
            handleAddList();
        }

        if(event.key === 'Escape'){
            handleInputChange();
        }
    };

    return (
        <>
        <li style={{ textDecoration: item.checked ? 'line-through' : 'none' }}>
            <div className="w-full flex flex-row justify-between">
                <div className="flex flex-row justify-center items-center">
                    <input 
                        type="checkbox" 
                        name={"checkbox-"+String(item.id)} 
                        id={"checkbox-"+String(item.id)} 
                        checked={item.checked} 
                        onChange={handleCheckboxChange}
                        className="mx-1 bg-transparent border-orange-500 text-orange-500"
                        /> 
                    {/* <p>{item.id}.</p> */}
                    {inputEnable === true ? (
                        <input 
                            type="text" 
                            name={"input-"+String(item.id)} 
                            id={"input-"+String(item.id)} 
                            value={inputValue} 
                            onChange={handleTextChange}
                            onKeyDown={handleKeyDownTextEvent}
                            autoFocus
                            className="px-1"/> 
                    ) : (
                        <button onClick={handleInputChange} className="px-1">{item.text}</button>
                    )
                    }
                </div>
                <div className="flex">
                    {inputEnable && (
                        <ButtonUpdate 
                            setCheckedInputI={handleAddList}
                            setCancelInputI={handleInputChange}
                            />)}
                        <ButtonAdd id={item.id} />
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

const ItemComponent:React.FC<{children:ReactNode}> = ({children}) => {    
    return (
        <ItemProvider>
            {children}
        </ItemProvider>
    );
}

export default function Page() {
    return (
        <ItemComponent>
            <div className="w-full h-screen bg-blue-950 flex flex-col items-center">
                <div className="w-1/2 py-2 mt-5 rounded-2xl flex text-center items-center justify-center text-orange-500 bg-white">
                    <svg xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24" strokeWidth={1.5} stroke="currentColor" className="mr-2 size-12">
                        <path strokeLinecap="round" strokeLinejoin="round" d="M9 12h3.75M9 15h3.75M9 18h3.75m3 .75H18a2.25 2.25 0 0 0 2.25-2.25V6.108c0-1.135-.845-2.098-1.976-2.192a48.424 48.424 0 0 0-1.123-.08m-5.801 0c-.065.21-.1.433-.1.664 0 .414.336.75.75.75h4.5a.75.75 0 0 0 .75-.75 2.25 2.25 0 0 0-.1-.664m-5.8 0A2.251 2.251 0 0 1 13.5 2.25H15c1.012 0 1.867.668 2.15 1.586m-5.8 0c-.376.023-.75.05-1.124.08C9.095 4.01 8.25 4.973 8.25 6.108V8.25m0 0H4.875c-.621 0-1.125.504-1.125 1.125v11.25c0 .621.504 1.125 1.125 1.125h9.75c.621 0 1.125-.504 1.125-1.125V9.375c0-.621-.504-1.125-1.125-1.125H8.25ZM6.75 12h.008v.008H6.75V12Zm0 3h.008v.008H6.75V15Zm0 3h.008v.008H6.75V18Z" />
                    </svg>
                    <h1>Todo List</h1>
                </div>
                
                <ModalList/>
            </div>
        </ItemComponent>
    );
}
