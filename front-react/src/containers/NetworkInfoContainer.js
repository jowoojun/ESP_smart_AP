import React, {Component} from 'react';

import {NetworkInfo, NetworkInfoSide} from '../components';


class NetworkInfoContainer extends Component{

    constructor(props){

        super(props);
    }

    render(){

        return(
            <div>
                <NetworkInfo />
                <NetworkInfoSide />
            </div>
        );
    }
}

export default NetworkInfoContainer
