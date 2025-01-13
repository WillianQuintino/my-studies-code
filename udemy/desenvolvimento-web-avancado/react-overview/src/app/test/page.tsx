"use client"
import { ReactNode, useEffect, useState } from "react";

interface IModalBottom {
    children:ReactNode
}
const ModalButton:React.FC<IModalBottom> = ({children}) => {
    return (
        <>
        <h1>Teste de Modal</h1>
        {children}
        </>
    );
}

type ButtonInterface = {
    increment:number;
    setIncrement:()=>void;
}
const ComponentButton = ({increment, setIncrement}:ButtonInterface) => {
    useEffect(()=>{
        console.log('Executa um vez ao carregar');
    }, []);
    return (
    <>
        <button onClick={setIncrement}>{increment}</button>
    </>
    );
}

export default function Page() {
    const [number, setNumber] = useState(0);
    const handleNumber = () => {
        setNumber((prev) => prev + 1);
        setNumber((prev) => prev + 1);
        setNumber((prev) => prev + 1);
    }

    useEffect(()=>{
        console.log(number);
    }, [number]);

    return (
        <ModalButton>
            <ComponentButton increment={number} setIncrement={handleNumber}/><br/>
            <ComponentButton increment={number} setIncrement={handleNumber}/>
            {number>10 ? (<h1>Maior que 10</h1>) : (<h1>Menor que 10</h1>)}
        </ModalButton>
    );
}
