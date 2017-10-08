import React, {Component} from 'react';

import {Refuse, RefuseAside} from '../components';


export default class RefuseContainer extends Component{

    constructor(props){

        super(props);
    }

    render(){

        return(
            <div>
                <Refuse />
                <RefuseAside />
            </div>
        );
    }
}
