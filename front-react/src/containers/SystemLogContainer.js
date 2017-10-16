import React, {Component} from 'react';

import {SystemLog, SystemLogAside} from '../components';
import {getLogInfo} from '../lib/toServer';
export default class SystemLogContainer extends Component{

    constructor(props){

        super(props);

        this.state = {
            logs : [],
        };
    }

    componentDidMount(){
        getLogInfo()
        .then((response) => {
            this.setState({logs : response.data.log});
        })
        .catch(error => console.log(error));
    }

    render(){

        return(
            <div>
                <SystemLog
                    logs={this.state.logs}
                />
                <SystemLogAside />
            </div>
        );
    }
}
