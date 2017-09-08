import React, {Component} from 'react';

import {NetworkInfo, NetworkInfoSide} from '../components';
import {ChangeModeButton} from '../components';


class NetworkInfoContainer extends Component{

    constructor(props){

        super(props);
    }

    render(){

        return(
            <div>
                <NetworkInfo />
                <NetworkInfoSide />
                <ChangeModeButton />
            </div>
        );
    }
}

export default NetworkInfoContainer
