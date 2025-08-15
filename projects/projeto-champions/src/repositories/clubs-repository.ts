import { ClubModel } from "../models/club-model";
import fs from "fs";

export const findAllClubs = async (): Promise<ClubModel[]> => {
    const data = await fs.promises.readFile("src/data/clubs.json", "utf-8");
    const database: ClubModel[] = JSON.parse(data);
    return database;
};
