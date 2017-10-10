import React, {Component} from 'react';

import {SystemLog, SystemLogAside} from '../components';

export default class SystemLogContainer extends Component{

    constructor(props){

        super(props);
    }

    render(){

        return(
            <div>
                <SystemLog />
                <SystemLogAside />
            </div>
        );
    }
}
