import { useItem } from "@/app/context/arrayList";
import { IList } from "@/app/todolist/page";
import { useState } from "react";

type ButtonUpdateInterface = {
    setCheckedInputI: ()=>void;
    setCancelInputI?: ()=>void;
}

export function listItem(list: IList[], id: number): IList | undefined {
    for (const item of list) {
        if (item.id === id) {
            return { ...item};
        }

        if (item.child) {
            const childItem = listItem(item.child, id);
            if (childItem) {
                return childItem;
            }
        }
    }

    return undefined;
}

export function updateItem(list: IList[], id: number, updatedItem?: Partial<IList>, updatedChild?: IList[], checked?:boolean): IList[] {
    return list.map(item => {
        if (item.id === id) {
            if(updatedItem === undefined) updatedItem = item;
            if(updatedChild){
                if (updatedItem === undefined) updatedItem = item;
                let child = (updatedItem.child !== undefined) ? updatedItem.child : [];
                updatedItem = {
                    'id': updatedItem.id,
                    'text': updatedItem.text,
                    'checked': updatedItem.checked,
                    'child': [...child, ...updatedChild]
                };
            } 
            if(checked !== undefined){
                if (updatedItem === undefined) updatedItem = item;
                let child = (updatedItem.child !== undefined) ? updatedItem.child : [];
                updatedItem = {
                    'id': updatedItem.id,
                    'text': updatedItem.text,
                    'checked': checked,
                    'child': child
                };
            } 
            return { ...item, ...updatedItem };
        }

        if (item.child) {
            item.child = updateItem(item.child, id, updatedItem, updatedChild);
        }

        return item;
    });
}

function removeItem(list: IList[], id: number): IList[] {
  return list.filter(item => {
    if (item.id === id) {
      return false;
    }

    if (item.child) {
      item.child = removeItem(item.child, id);
    }

    return true;
  });
}

export const ButtonAdd: React.FC<{id: number}> = ({id}) =>{
    const{arrayList, setArrayList, findMaxId} = useItem();
    let lastId = findMaxId() + 1;

    const [inputMainAddEnable, setCheckedInputMainAdd] = useState(false);
    const [inputValue, setInputValue] = useState('');

    const handleInputChange = () => {
        setCheckedInputMainAdd(!inputMainAddEnable);
    };

    const handleAddList = () => {
        if (inputValue.trim() !== '') {
            const newId = findMaxId() + 1;
            const newItem: IList[] = [{
                id: newId,
                text: inputValue.trim(),
                checked: false,
                father: id
            }];
            setArrayList(updateItem(arrayList, id, undefined, newItem));
            setInputValue('');
            handleInputChange();
        }
    };

    const handleTextChange = (event: React.ChangeEvent<HTMLInputElement>) => {
        setInputValue(event.target.value);
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
        {inputMainAddEnable ? (
            <>
            <div className="flex flex-row justify-center items-center">
                <input 
                    type="text" 
                    name={"input-0"} 
                    id={"input-0"} 
                    value={inputValue} 
                    onChange={handleTextChange} 
                    onKeyDown={handleKeyDownTextEvent}
                    autoFocus
                    className="px-1"/> 
                    <ButtonUpdate setCheckedInputI={handleAddList} setCancelInputI={handleInputChange}/>
            </div>
            </>
        ) : (
            <button onClick={handleInputChange}>
                <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 24" fill="currentColor" className="svg-btn size-6">
                    <path fillRule="evenodd" d="M12 2.25c-5.385 0-9.75 4.365-9.75 9.75s4.365 9.75 9.75 9.75 9.75-4.365 9.75-9.75S17.385 2.25 12 2.25ZM12.75 9a.75.75 0 0 0-1.5 0v2.25H9a.75.75 0 0 0 0 1.5h2.25V15a.75.75 0 0 0 1.5 0v-2.25H15a.75.75 0 0 0 0-1.5h-2.25V9Z" clipRule="evenodd" />
                </svg>
            </button>
        )}
        </>
    );
}

export const ButtonUpdate = ({setCheckedInputI, setCancelInputI}:ButtonUpdateInterface) => {

    return (
        <>
        <button onClick={setCancelInputI} >
            <svg xmlns="http://www.w3.org/2000/svg" fill="none" viewBox="0 0 24 24" strokeWidth={1.5} stroke="currentColor" className="svg-btn size-6">
                <path strokeLinecap="round" strokeLinejoin="round" d="m9.75 9.75 4.5 4.5m0-4.5-4.5 4.5M21 12a9 9 0 1 1-18 0 9 9 0 0 1 18 0Z" />
            </svg>
        </button>
        <button onClick={setCheckedInputI} >
            <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 24" fill="currentColor" className="svg-btn size-6">
                <path d="M3.478 2.404a.75.75 0 0 0-.926.941l2.432 7.905H13.5a.75.75 0 0 1 0 1.5H4.984l-2.432 7.905a.75.75 0 0 0 .926.94 60.519 60.519 0 0 0 18.445-8.986.75.75 0 0 0 0-1.218A60.517 60.517 0 0 0 3.478 2.404Z" />
            </svg>
        </button>
        </>
    );
}


export const ButtonCopy: React.FC<{id: number}> = ({id}) => {
    const{arrayList, setArrayList, findMaxId} = useItem();
    const handleAddList = () => {
        let newItem = listItem(arrayList, id);
        if(newItem) {
            newItem.id = findMaxId()+1;
            newItem.father = 0;
            newItem.child = undefined;
            setArrayList([...arrayList, newItem]);
        }
    };
    return (
        <>
        <button onClick={handleAddList}>
            <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 24" fill="currentColor" className="svg-btn size-6">
                <path fillRule="evenodd" d="M7.502 6h7.128A3.375 3.375 0 0 1 18 9.375v9.375a3 3 0 0 0 3-3V6.108c0-1.505-1.125-2.811-2.664-2.94a48.972 48.972 0 0 0-.673-.05A3 3 0 0 0 15 1.5h-1.5a3 3 0 0 0-2.663 1.618c-.225.015-.45.032-.673.05C8.662 3.295 7.554 4.542 7.502 6ZM13.5 3A1.5 1.5 0 0 0 12 4.5h4.5A1.5 1.5 0 0 0 15 3h-1.5Z" clipRule="evenodd" />
                <path fillRule="evenodd" d="M3 9.375C3 8.339 3.84 7.5 4.875 7.5h9.75c1.036 0 1.875.84 1.875 1.875v11.25c0 1.035-.84 1.875-1.875 1.875h-9.75A1.875 1.875 0 0 1 3 20.625V9.375ZM6 12a.75.75 0 0 1 .75-.75h.008a.75.75 0 0 1 .75.75v.008a.75.75 0 0 1-.75.75H6.75a.75.75 0 0 1-.75-.75V12Zm2.25 0a.75.75 0 0 1 .75-.75h3.75a.75.75 0 0 1 0 1.5H9a.75.75 0 0 1-.75-.75ZM6 15a.75.75 0 0 1 .75-.75h.008a.75.75 0 0 1 .75.75v.008a.75.75 0 0 1-.75.75H6.75a.75.75 0 0 1-.75-.75V15Zm2.25 0a.75.75 0 0 1 .75-.75h3.75a.75.75 0 0 1 0 1.5H9a.75.75 0 0 1-.75-.75ZM6 18a.75.75 0 0 1 .75-.75h.008a.75.75 0 0 1 .75.75v.008a.75.75 0 0 1-.75.75H6.75a.75.75 0 0 1-.75-.75V18Zm2.25 0a.75.75 0 0 1 .75-.75h3.75a.75.75 0 0 1 0 1.5H9a.75.75 0 0 1-.75-.75Z" clipRule="evenodd" />
            </svg>
        </button>
        </>
    );
}

type ButtonRemoveInterface = {
    id: number;
}
export const ButtonRemove: React.FC<ButtonRemoveInterface> = ({id}) => {
    const{arrayList, setArrayList} = useItem();
    const handleRemoveItem = () => {
        setArrayList(removeItem(arrayList, id));
    };

    return (
        <>
        <button onClick={handleRemoveItem}>            
            <span></span>
            <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 24" fill="currentColor" className="svg-btn size-6">
                <path fillRule="evenodd" d="M16.5 4.478v.227a48.816 48.816 0 0 1 3.878.512.75.75 0 1 1-.256 1.478l-.209-.035-1.005 13.07a3 3 0 0 1-2.991 2.77H8.084a3 3 0 0 1-2.991-2.77L4.087 6.66l-.209.035a.75.75 0 0 1-.256-1.478A48.567 48.567 0 0 1 7.5 4.705v-.227c0-1.564 1.213-2.9 2.816-2.951a52.662 52.662 0 0 1 3.369 0c1.603.051 2.815 1.387 2.815 2.951Zm-6.136-1.452a51.196 51.196 0 0 1 3.273 0C14.39 3.05 15 3.684 15 4.478v.113a49.488 49.488 0 0 0-6 0v-.113c0-.794.609-1.428 1.364-1.452Zm-.355 5.945a.75.75 0 1 0-1.5.058l.347 9a.75.75 0 1 0 1.499-.058l-.346-9Zm5.48.058a.75.75 0 1 0-1.498-.058l-.347 9a.75.75 0 0 0 1.5.058l.345-9Z" clipRule="evenodd" />
            </svg>
        </button>
        </>
    );
}

export const ButtonMainAdd:React.FC= () => {
    const{arrayList, setArrayList, findMaxId} = useItem();
    let lastId = findMaxId() + 1;

    const [inputMainAddEnable, setCheckedInputMainAdd] = useState(false);
    const [inputValue, setInputValue] = useState('');

    const handleInputChange = () => {
        setCheckedInputMainAdd(!inputMainAddEnable);
    };

    const handleAddList = () => {
        if (inputValue.trim() !== '') {
            const newId = findMaxId() + 1;
            const newItem: IList = {
                id: newId,
                text: inputValue.trim(),
                checked: false,
                father: 0
            };
            setArrayList([...arrayList, newItem]);
            setInputValue('');
            handleInputChange();
        }
    };

    const handleTextChange = (event: React.ChangeEvent<HTMLInputElement>) => {
        setInputValue(event.target.value);
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
        {inputMainAddEnable ? (
                        <>
                        <div className="flex flex-row justify-center items-center">
                            <input 
                                type="text" 
                                name={"input-0"} 
                                id={"input-0"} 
                                value={inputValue} 
                                onChange={handleTextChange} 
                                onKeyDown={handleKeyDownTextEvent}
                                autoFocus
                                className="m-2 py-2 px-3"/> 
                                <ButtonUpdate setCheckedInputI={handleAddList} setCancelInputI={handleInputChange} />
                        </div>
                        </>
                    ) : (
                        <div className="w-full flex justify-center">
                            <button className="py-1 px-2 flex flex-row bg-orange-400 rounded-lg border border-orange-800 shadow shadow-orange-950" onClick={handleInputChange}>
                                <span className="pr-1">Adicionar</span>
                                <svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 24 24" fill="currentColor" className="size-6 text-orange-50">
                                    <path fillRule="evenodd" d="M12 2.25c-5.385 0-9.75 4.365-9.75 9.75s4.365 9.75 9.75 9.75 9.75-4.365 9.75-9.75S17.385 2.25 12 2.25ZM12.75 9a.75.75 0 0 0-1.5 0v2.25H9a.75.75 0 0 0 0 1.5h2.25V15a.75.75 0 0 0 1.5 0v-2.25H15a.75.75 0 0 0 0-1.5h-2.25V9Z" clipRule="evenodd" />
                                </svg>
                            </button>
                        </div>
                    )}
        
        </>
    );
}