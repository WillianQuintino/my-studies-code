import fastify from "fastify";
import cors from "@fastify/cors";

const server = fastify({ logger: true });

server.register(cors, {
    origin: "*"
});

const teams = [
  { id: 1, name: "McLaren", base: "Woking, United Kingdom" },
  { id: 2, name: "Mercedes", base: "Brackley, United Kingdom" },
  { id: 3, name: "Red Bull Racing", base: "Milton Keynes, United Kingdom" },
  { id: 4, name: "Ferrari", base: "Maranello, Italy" },
  { id: 5, name: "Aston Martin", base: "Silverstone, United Kingdom" },
  { id: 6, name: "Alpine", base: "Enstone, United Kingdom" },
  { id: 7, name: "Williams", base: "Grove, United Kingdom" },
  { id: 8, name: "Haas", base: "Kannapolis, North Carolina, USA" },
  { id: 9, name: "Sauber (Stake F1 Team)", base: "Hinwil, Switzerland" },
  { id: 10, name: "Racing Bulls", base: "Faenza, Italy" }
];


const drivers = [
    {id: 1, name: "Max Verstappen", team: "Read Bull Racing"},
    {id: 2, name: "Lewis Hamilton", team: "Ferrari"},
    {id: 3, name: "Lando Norris", team: "McLaren"}
]

server.get("/teams", async(request, response) => {
    response.type("application/json").code(200);
    return { teams };
});

server.get("/drivers", async(request, response) => {
    response.type("application/json").code(200);
    return {drivers};
});

interface DriveParams {
    id: string
}

server.get<{Params: DriveParams}>("/drivers/:id", async(request, response) => {
    const id = parseInt(request.params.id);
    const driver = drivers.find((d) => d.id === id);

    if(!driver){
        response.type("application/json").code(404);
        return { message: "Drive Not Found"};
    } else {
        response.type("application/json").code(200);
        return { driver };
    }
});

server.listen({port: 3333}, () => {
    console.info("Server init");
});