import { PlayerModel } from "../models/player-model";
import { StatisticsModel } from "../models/statistics-model";
import fs from "fs";

export const findAllPlayers = async (): Promise<PlayerModel[]> => {
    const data = await fs.promises.readFile("src/data/players.json", "utf-8");
    const database: PlayerModel[] = JSON.parse(data);
    return database;
};

export const findPlayerById = async (id: number): Promise<PlayerModel | undefined> => {
    const players = await findAllPlayers();
    return players.find(player => player.id === id);
};

export const insertPlayer = async (player: PlayerModel): Promise<void> => {
    const players = await findAllPlayers();
    players.push(player);
    await fs.promises.writeFile("src/data/players.json", JSON.stringify(players, null, 2), "utf-8");
};

export const deletePlayerById = async (id: number): Promise<boolean> => {
    const players = await findAllPlayers();
    const playerIndex = players.findIndex(player => player.id === id);
    if (playerIndex !== -1) {
        players.splice(playerIndex, 1);
        await fs.promises.writeFile("src/data/players.json", JSON.stringify(players, null, 2), "utf-8");
        return true;
    }
    return false;
};

export const findAndModifyPlayer = async (id: number, statistics: StatisticsModel): Promise<PlayerModel | undefined> => {
    const players = await findAllPlayers();
    const playerIndex = players.findIndex(player => player.id === id);
    if (playerIndex !== -1) {
        players[playerIndex].statistics = statistics;
        await fs.promises.writeFile("src/data/players.json", JSON.stringify(players, null, 2), "utf-8");
        return players[playerIndex];
    }

    return undefined;
}
