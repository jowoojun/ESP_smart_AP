import axios from 'axios';

const kUrl = "http://localhost:8000";

export function getInternetInfo(){
    return axios.get(`${kUrl}/api`);
}
