import React, { createContext, ReactNode, useContext, useEffect, useState } from "react";
import { IList } from "../todolist/page";

interface IArrayList {
    arrayList:IList[],
    setArrayList: (value:IList[]) => void,
    findMaxId: ()=>number
}

interface IItemProvider {
    children:ReactNode
}

const ItemContext = createContext<IArrayList>({} as IArrayList);

export const ItemProvider:React.FC<IItemProvider> = ({children}) => {

    const [arrayList, setArrayList] = useState<IList[]>((localStorage.getItem('List')?JSON.parse(localStorage.getItem('List') as string):[]));
    function findMaxId(): number {
        let maxId = 0;

        function traverse(items: IList[]) {
            for (const item of items) {
                maxId = Math.max(maxId, item.id);
                if (item.child && item.child.length > 0) {
                    traverse(item.child);
                }
            }
        }
        traverse(arrayList);
        return maxId;
    }

    useEffect(() => {
        localStorage.setItem('List', JSON.stringify(arrayList));
    }, [arrayList]);

    return (
        <ItemContext.Provider value={{
            arrayList, setArrayList, findMaxId
        }}>
            {children}
        </ItemContext.Provider>
    )
}

export const useItem = ():IArrayList => {
    const context = useContext(ItemContext)
    if(!context){
       throw new Error('Falha ao Inicializar o Contexto'); 
    }
    return context
}