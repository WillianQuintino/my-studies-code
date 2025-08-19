import express, { json } from "express";
import cors from "cors";

import router from "./routes";

function createApp() {
    const app = express();

    app.use(json());
    app.use("/api", router);

    const corsOptions = {
        origin: "http://localhost:3000",
        methods: ["GET", "POST", "PUT", "DELETE"],
        allowedHeaders: ["Content-Type", "Authorization"]
    };

    app.use(cors());

    return app;
}

export default createApp;